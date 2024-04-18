object Form_analient: TForm_analient
  Left = 256
  Top = 157
  Width = 720
  Height = 480
  Caption = 'Analitico Entradas Proveedor/Articulo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  FormStyle = fsMDIChild
  OldCreateOrder = False
  Position = poDefault
  Visible = True
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 704
    Height = 42
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object pnl_datos: TGroupBox
      Left = 0
      Top = 0
      Width = 345
      Height = 42
      Align = alLeft
      Caption = 'Fecha:'
      TabOrder = 0
      object lbl_vigencia: TLabel
        Left = 6
        Top = 18
        Width = 63
        Height = 13
        Caption = 'Fecha Inicial:'
      end
      object lbl_corte: TLabel
        Left = 175
        Top = 19
        Width = 58
        Height = 13
        Caption = 'Fecha Final:'
      end
      object date_ini: TDateTimePicker
        Left = 69
        Top = 14
        Width = 90
        Height = 22
        CalAlignment = dtaLeft
        Date = 38762.7111857986
        Time = 38762.7111857986
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 0
      end
      object date_fin: TDateTimePicker
        Left = 237
        Top = 14
        Width = 92
        Height = 22
        CalAlignment = dtaLeft
        Date = 38982.3491966782
        Time = 38982.3491966782
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 1
      end
    end
    object BitBtn1: TBitBtn
      Left = 380
      Top = 10
      Width = 76
      Height = 26
      TabOrder = 1
      OnClick = BitBtn1Click
      Kind = bkOK
    end
  end
  object dbgrd_renglones: TdxDBGrid
    Left = 0
    Top = 42
    Width = 704
    Height = 400
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'CODINV'
    ShowGroupPanel = True
    ShowSummaryFooter = True
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    PopupMenu = PopupMenu1
    TabOrder = 1
    DataSource = dts_datos
    Filter.Active = True
    Filter.AutoDataSetFilter = True
    Filter.Criteria = {00000000}
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    object dbgrd_renglonesPROVE: TdxDBGridMaskColumn
      Caption = 'Proveedor'
      Sorted = csDown
      Visible = False
      Width = 67
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PROVE'
      GroupIndex = 0
    end
    object dbgrd_renglonesCODIGO: TdxDBGridMaskColumn
      Caption = 'Código'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CODINV'
    end
    object dbgrd_renglonesDESCRI: TdxDBGridMaskColumn
      Caption = 'Articulo'
      Width = 155
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DESCRI'
    end
    object dbgrd_renglonesNUMERO: TdxDBGridMaskColumn
      Caption = 'Entrada #'
      Width = 56
      BandIndex = 0
      RowIndex = 0
      FieldName = 'NUMERO'
    end
    object dbgrd_renglonesFECHA: TdxDBGridDateColumn
      Caption = 'Fecha'
      Width = 53
      BandIndex = 0
      RowIndex = 0
      FieldName = 'FECHA'
    end
    object dbgrd_renglonesCOSTON: TdxDBGridMaskColumn
      Caption = 'Costo U/IVA'
      Width = 53
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COSTON'
    end
  end
  object qry_min: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select min(numero) as min from entradas where'
      
        #9'fecha between :FECINI and :FECFIN and entradas.tipo= :TPENT and' +
        ' cia= :CIA')
    Left = 88
    Top = 136
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_max: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select max(numero) as max from entradas where'
      
        #9'fecha between :FECINI and :FECFIN and entradas.tipo= :TPENT and' +
        ' cia= :CIA')
    Left = 88
    Top = 168
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_datos: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select unique'
      'a.prove,d.nombre,b.codinv,c.descri,c.coston,'
      'a.fecha,a.numero'
      'from entradas a join renentra b on a.tipo = '
      'b.tipo and a.alm = b.alm and a.numero = '
      'b.numero and a.cia = b.cia'
      'join inven c on b.codinv = c.codigo and '
      'b.cia = c.cia'
      'join proveedor d on a.prove = d.codigo and '
      'a.cia = d.cia '
      'where a.fecha between :FECINI and :FECFIN'
      'and a.tipo= :TPENT and'
      'a.cia= :CIA'
      'order by a.prove,b.codinv,a.numero '
      ' ')
    Left = 88
    Top = 208
    ParamData = <
      item
        DataType = ftDateTime
        Name = 'FECINI'
        ParamType = ptUnknown
      end
      item
        DataType = ftDateTime
        Name = 'FECFIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object qry_unid: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select count(*) as unidad,sum(importe*((piva/100)+1)) as import ' +
        'from renentra where'
      
        #9'tipo= :TPENT and numero= :NUM  and codinv= :CODINV and cia= :CI' +
        'A')
    Left = 88
    Top = 242
    ParamData = <
      item
        DataType = ftString
        Name = 'TPENT'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'NUM'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'CODINV'
        ParamType = ptUnknown
      end
      item
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end>
  end
  object dts_datos: TDataSource
    DataSet = qry_datos
    Left = 122
    Top = 209
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 456
    Top = 184
    object exportar: TAction
      Caption = 'Exportar a...'
      ImageIndex = 9
      OnExecute = exportarExecute
    end
    object imprir_reporte: TAction
      Caption = 'Reporte'
      ImageIndex = 21
      OnExecute = imprir_reporteExecute
    end
  end
  object PopupMenu1: TPopupMenu
    Left = 216
    Top = 168
    object Exportara1: TMenuItem
      Action = exportar
    end
  end
end
