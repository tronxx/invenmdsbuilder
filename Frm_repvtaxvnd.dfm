object Form_repvtaxvnd: TForm_repvtaxvnd
  Left = 258
  Top = 157
  Width = 696
  Height = 480
  Caption = 'Analítico de Costo de Ventas/Cancelaciones/Mayoreo'
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
    Width = 688
    Height = 137
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object grp_tiporep: TRadioGroup
      Left = 181
      Top = 8
      Width = 100
      Height = 129
      Caption = 'Reporte de'
      ItemIndex = 0
      Items.Strings = (
        'Menudeo'
        'Fonacot'
        'Fide'
        'Celular')
      TabOrder = 0
    end
    object grp_netobru: TRadioGroup
      Left = 282
      Top = 8
      Width = 100
      Height = 129
      Caption = 'Reporte de'
      ItemIndex = 0
      Items.Strings = (
        'Brutas'
        'Netas'
        'Cancelaciones')
      TabOrder = 1
    end
    object grp_statcan: TRadioGroup
      Left = 383
      Top = 8
      Width = 130
      Height = 129
      Caption = 'Status de Cancelación'
      ItemIndex = 0
      Items.Strings = (
        'Sin Importar Status'
        'Cancelacion'
        'No Cancelados')
      TabOrder = 2
    end
    object grp_statsino: TRadioGroup
      Left = 515
      Top = 8
      Width = 100
      Height = 129
      Caption = 'Status Si/No'
      ItemIndex = 0
      Items.Strings = (
        'Sin Importar'
        'Solo Status 1'
        'Solo Status 2')
      TabOrder = 3
    end
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 180
      Height = 137
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 4
      object Label1: TLabel
        Left = 5
        Top = 16
        Width = 60
        Height = 13
        Caption = 'Fecha Inicial'
      end
      object Label2: TLabel
        Left = 5
        Top = 40
        Width = 55
        Height = 13
        Caption = 'Fecha Final'
      end
      object date_fecini: TDateTimePicker
        Left = 77
        Top = 13
        Width = 97
        Height = 21
        CalAlignment = dtaLeft
        Date = 38981.5149197569
        Time = 38981.5149197569
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 0
      end
      object date_fecfin: TDateTimePicker
        Left = 77
        Top = 37
        Width = 97
        Height = 21
        CalAlignment = dtaLeft
        Date = 38981.5149197569
        Time = 38981.5149197569
        DateFormat = dfShort
        DateMode = dmComboBox
        Kind = dtkDate
        ParseInput = False
        TabOrder = 1
      end
      object BitBtn1: TBitBtn
        Left = 77
        Top = 64
        Width = 75
        Height = 25
        TabOrder = 2
        OnClick = BitBtn1Click
        Kind = bkOK
      end
      object BitBtn2: TBitBtn
        Left = 80
        Top = 96
        Width = 75
        Height = 25
        Action = imprimir
        Caption = 'Imprimir'
        TabOrder = 3
        Glyph.Data = {
          36040000424D3604000000000000360000002800000010000000100000000100
          2000000000000004000000000000000000000000000000000000FF00FF000000
          0000000000000000000000000000000000000000000000000000000000000000
          00000000000000000000000000000000000000000000FF00FF0000000000BDBD
          BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
          BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD000000000000000000BDBD
          BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBD
          BD00BDBDBD00BDBDBD00BDBDBD00BDBDBD00BDBDBD0000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          000000000000000000000000000000000000000000000000000000000000FFFF
          FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
          FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD000000000000000000BDBD
          BD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBD
          BD00FFFFFF00BDBDBD00FFFFFF000000FF00FFFFFF000000000000000000FFFF
          FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD00FFFF
          FF00BDBDBD00FFFFFF00BDBDBD00FFFFFF00BDBDBD0000000000000000000000
          0000000000000000000000000000000000000000000000000000000000000000
          0000000000000000000000000000000000000000000000000000FF00FF00FF00
          FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF0000000000FFFFFF0000000000000000000000000000000000FFFF
          FF0000000000FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFFFF00FFFF
          FF00FFFFFF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF0000000000FFFFFF000000000000000000FFFFFF00000000000000
          0000000000000000000000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF0000000000FFFF
          FF00FFFFFF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF0000000000FFFFFF0000000000BDBDBD00FFFFFF0000000000FFFF
          FF0000000000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF0000000000FFFFFF00FFFFFF00FFFFFF00FFFFFF00000000000000
          0000FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00
          FF00FF00FF00000000000000000000000000000000000000000000000000FF00
          FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00FF00}
      end
    end
  end
  object dbgrd_renglones: TdxDBGrid
    Left = 0
    Top = 137
    Width = 688
    Height = 309
    Bands = <
      item
      end>
    DefaultLayout = True
    HeaderPanelRowCount = 1
    KeyField = 'CODIGO'
    ShowGroupPanel = True
    ShowSummaryFooter = True
    SummaryGroups = <>
    SummarySeparator = ', '
    Align = alClient
    PopupMenu = PopupMenu1
    TabOrder = 1
    DataSource = dts_analisma
    Filter.Active = True
    Filter.AutoDataSetFilter = True
    Filter.Criteria = {00000000}
    OptionsDB = [edgoCancelOnExit, edgoCanDelete, edgoCanInsert, edgoCanNavigation, edgoConfirmDelete, edgoLoadAllRecords, edgoUseBookmarks]
    OptionsView = [edgoAutoWidth, edgoBandHeaderWidth, edgoRowSelect, edgoUseBitmap]
    OnCustomDraw = dbgrd_renglonesCustomDraw
    object dbgrd_renglonesZONA: TdxDBGridMaskColumn
      Caption = 'Zona'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'ZONAINV'
    end
    object dbgrd_renglonesVEND: TdxDBGridMaskColumn
      Caption = 'Vendedor'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'VEND'
    end
    object dbgrd_renglonesRECEMI: TdxDBGridMaskColumn
      Caption = 'P.Vta'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'RECEMI'
    end
    object dbgrd_renglonesNSALIDA: TdxDBGridMaskColumn
      Caption = 'Num.Salida'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'NUMERO'
    end
    object dbgrd_renglonesLINEA: TdxDBGridMaskColumn
      Caption = 'Linea'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'LINEA'
    end
    object dbgrd_renglonesCODIGO: TdxDBGridMaskColumn
      Caption = 'Codigo'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'CODIGO'
    end
    object dbgrd_renglonesDESCRI: TdxDBGridMaskColumn
      Caption = 'Descripción'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'DESCRI'
    end
    object dbgrd_renglonesEMPAQE: TdxDBGridMaskColumn
      Caption = 'Empaque'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'EMPAQE'
    end
    object dbgrd_renglonesCOSTOU: TdxDBGridCurrencyColumn
      Caption = 'Costo Unit'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COSTOU'
    end
    object dbgrd_renglonesPRVTA: TdxDBGridCurrencyColumn
      Caption = 'Precio.Vta'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'PRVTA'
    end
    object dbgrd_renglonesUNIDS: TdxDBGridMaskColumn
      Caption = 'Unidades'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'UNIDS'
      SummaryFooterType = cstSum
      SummaryFooterField = 'UNIDS'
      SummaryFooterFormat = '0'
    end
    object dbgrd_renglonesCOSTOTOT: TdxDBGridCurrencyColumn
      Caption = 'Total'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'COSTOTOT'
      SummaryFooterType = cstSum
      SummaryFooterField = 'COSTOTOT'
      SummaryFooterFormat = '$,0.00;-$,0.00'
    end
  end
  object qry_analisma: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      
        'select d.zonainv, b.vend, b.recemi, b.numero, a.fecha, c.linea, ' +
        'b.recemi, c.codigo, c.descri, c.empaqe, b.costou,'
      #9'b.prvta * (b.piva/100+1) as prvta,'
      #9'(b.unids * factor) as unids,'
      '        (b.costou * (b.piva/100+1) * factor) as costotot'
      #9'from inv_tpvtatmp f'
      '        join entradas a on f.tiposal=a.tipo'
      '        join renentra b on a.numero=b.numero'
      '        and a.alm=b.alm and a.numero=b.numero and a.cia=b.cia'
      
        '        join inven c on b.codinv=c.codigo and b.cia=c.cia and a.' +
        'tipo=b.tipo'
      '        join ubivtainv d on a.alm = d.alm and b.recemi = d.pvta'
      '        where'
      
        '        f.idtarea = :IDTAREA and a.fecha between :FECINI and :FE' +
        'CFIN and a.cia= :CIA'
      '        and (b.siono  = :SIONO1  or b.siono  = :SIONO2)'
      '        and (b.entcan = :ENTCAN1 or b.entcan = :ENTCAN2)'
      
        '        order by d.zonainv,b.vend, b.recemi, b.numero, a.fecha, ' +
        'linea,codigo,c.descri,c.empaqe, costou,prvta'
      ''
      ' ')
    UpdateObject = uqry_gpodiary
    Left = 312
    Top = 200
    ParamData = <
      item
        DataType = ftInteger
        Name = 'IDTAREA'
        ParamType = ptUnknown
      end
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
        DataType = ftInteger
        Name = 'CIA'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SIONO1'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'SIONO2'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ENTCAN1'
        ParamType = ptUnknown
      end
      item
        DataType = ftString
        Name = 'ENTCAN2'
        ParamType = ptUnknown
      end>
  end
  object uqry_gpodiary: TUpdateSQL
    ModifySQL.Strings = (
      'update gpodiary'
      'set'
      '  DESCRI = :DESCRI,'
      '  IMPRIME = :IMPRIME'
      'where'
      '  IDGPODIARY = :OLD_IDGPODIARY')
    InsertSQL.Strings = (
      'insert into gpodiary'
      '  (IDGPODIARY, GRUPO, DESCRI, IMPRIME, CIA)'
      'values'
      '  (:IDGPODIARY, :GRUPO, :DESCRI, :IMPRIME, :CIA)')
    DeleteSQL.Strings = (
      'delete from gpodiary'
      'where'
      '  IDGPODIARY = :OLD_IDGPODIARY')
    Left = 342
    Top = 200
  end
  object dts_analisma: TDataSource
    AutoEdit = False
    DataSet = qry_analisma
    Left = 372
    Top = 200
  end
  object PopupMenu1: TPopupMenu
    Left = 256
    Top = 248
    object Exportara1: TMenuItem
      Action = exporta_dbgrd
    end
  end
  object ActionList1: TActionList
    Images = dm.ImageList1
    Left = 552
    Top = 280
    object exporta_dbgrd: TAction
      Caption = 'Exportar a...'
      ImageIndex = 19
      OnExecute = exporta_dbgrdExecute
    end
    object imprimir: TAction
      Caption = 'Imprimir'
      ImageIndex = 21
      OnExecute = imprimirExecute
    end
  end
end
