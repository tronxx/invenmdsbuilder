object Form_analivtacyc: TForm_analivtacyc
  Left = 263
  Top = 140
  Width = 700
  Height = 480
  Caption = 'Analítico de Costo de Ventas/Cancelaciones'
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
    Width = 692
    Height = 137
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Panel2: TPanel
      Left = 0
      Top = 0
      Width = 180
      Height = 137
      Align = alLeft
      BevelOuter = bvNone
      TabOrder = 0
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
        Top = 72
        Width = 75
        Height = 25
        TabOrder = 2
        OnClick = BitBtn1Click
        Kind = bkOK
      end
    end
    object grp_parametros: TGroupBox
      Left = 180
      Top = 0
      Width = 512
      Height = 137
      Align = alClient
      Caption = 'Parámetros'
      TabOrder = 1
      object Label5: TLabel
        Left = 62
        Top = 43
        Width = 78
        Height = 13
        Caption = 'Ventas o Cancel'
      end
      object Label6: TLabel
        Left = 79
        Top = 67
        Width = 61
        Height = 13
        Caption = 'Status Si/No'
      end
      object Label7: TLabel
        Left = 21
        Top = 91
        Width = 119
        Height = 13
        Caption = 'Artículos de Cancelación'
      end
      object lbl_contycred: TLabel
        Left = 44
        Top = 115
        Width = 96
        Height = 13
        Caption = 'Contado/Crédito/Tc'
      end
      object Label3: TLabel
        Left = 344
        Top = 19
        Width = 56
        Height = 13
        Caption = 'Linea Inicial'
      end
      object Label4: TLabel
        Left = 344
        Top = 43
        Width = 51
        Height = 13
        Caption = 'Linea Final'
      end
      object Label9: TLabel
        Left = 51
        Top = 19
        Width = 89
        Height = 13
        Caption = 'Reporte de Ventas'
      end
      object lbl_ptvtini: TLabel
        Left = 345
        Top = 67
        Width = 56
        Height = 13
        Caption = 'P.Vta Inicial'
      end
      object lbl_ptvtfin: TLabel
        Left = 345
        Top = 91
        Width = 51
        Height = 13
        Caption = 'P.Vta Final'
      end
      object cmb_netobru: TComboBox
        Left = 144
        Top = 40
        Width = 180
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 1
        Items.Strings = (
          'Ventas Brutas'
          'Ventas Netas'
          'Cancelaciones')
      end
      object cmb_statsino: TComboBox
        Left = 144
        Top = 64
        Width = 180
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 2
        Items.Strings = (
          'Sin Importar Status 1/2'
          'Solo Status 1'
          'Solo Status 2')
      end
      object cmb_statcan: TComboBox
        Left = 144
        Top = 88
        Width = 180
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 3
        Items.Strings = (
          'Sin importar Status de Cancelación'
          'Solo Con Status Cancelado'
          'Solo Sin Status Cancelado')
      end
      object cmb_contycre: TComboBox
        Left = 144
        Top = 112
        Width = 180
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 4
        Items.Strings = (
          'Contado, Crédito, TC'
          'Solo Contado'
          'Solo Crédito'
          'Solo TC')
      end
      object edt_prlin: TEdit
        Left = 408
        Top = 16
        Width = 50
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 5
        OnDblClick = edt_prlinDblClick
      end
      object edt_ullin: TEdit
        Left = 408
        Top = 40
        Width = 50
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 6
      end
      object cmb_tiporep: TComboBox
        Left = 144
        Top = 16
        Width = 180
        Height = 21
        Style = csDropDownList
        ItemHeight = 13
        TabOrder = 0
        OnChange = cmb_tiporepChange
        Items.Strings = (
          'Menudeo'
          'Fide'
          'Fonacot'
          'Menudeo, Fonacot y Fide'
          'Mayoreo'
          'Celular'
          'Entradas')
      end
      object edt_ptvtini: TEdit
        Left = 408
        Top = 64
        Width = 50
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 7
      end
      object edt_ptvtfin: TEdit
        Left = 408
        Top = 88
        Width = 50
        Height = 21
        CharCase = ecUpperCase
        TabOrder = 8
      end
    end
  end
  object dbgrd_renglones: TdxDBGrid
    Left = 0
    Top = 137
    Width = 692
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
    object dbgrd_renglonesCONT: TdxDBGridMaskColumn
      Caption = 'Cont/Cred'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'folent'
    end
    object dbgrd_renglonesUBICA: TdxDBGridMaskColumn
      Caption = 'Ubica'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'recemi'
    end
    object dbgrd_renglonesFecha: TdxDBGridMaskColumn
      Caption = 'Fecha'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'fecha'
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
    object dbgrd_renglonesNombre: TdxDBGridMaskColumn
      Caption = 'Nombre'
      BandIndex = 0
      RowIndex = 0
      FieldName = 'nombre'
    end
  end
  object qry_analisma: TQuery
    CachedUpdates = True
    DatabaseName = 'manvehi'
    Filtered = True
    SQL.Strings = (
      'select  b.folent, b.recemi, a.fecha, c.linea, c.codigo,'
      '        c.descri, c.empaqe, b.costou,'
      #9'b.prvta * (b.piva/100+1) as prvta,'
      #9'b.unids,'
      '        (b.costou * (b.piva/100+1) * factor) as costotot,'
      '        concepto as nombre'
      #9'from inv_tpvtatmp f'
      '        join entradas a on f.tiposal=a.tipo'
      '        join renentra b on a.numero=b.numero'
      '        and a.alm=b.alm and a.numero=b.numero and a.cia=b.cia'
      
        '        join inven c on b.codinv=c.codigo and b.cia=c.cia and a.' +
        'tipo=b.tipo'
      '        join conceps e on b.persenvrec = e.ncon'
      '        where'
      
        '        f.idtarea = :IDTAREA and a.fecha between :FECINI and :FE' +
        'CFIN and a.cia= :CIA'
      '        and (b.siono  = :SIONO1  or b.siono  = :SIONO2)'
      '        and (b.entcan = :ENTCAN1 or b.entcan = :ENTCAN2)'
      '        and (b.folent = :CONTADO or b.folent = :CREDITO)'
      '        and c.linea between :PRLIN and :ULLIN'
      '        order by b.folent, b.recemi,a.fecha,linea,codigo,'
      '        c.descri,c.empaqe, costou,prvta')
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
      end
      item
        DataType = ftUnknown
        Name = 'CONTADO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'CREDITO'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'PRLIN'
        ParamType = ptUnknown
      end
      item
        DataType = ftUnknown
        Name = 'ULLIN'
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
    Left = 552
    Top = 280
    object exporta_dbgrd: TAction
      Caption = 'Exportar a...'
      OnExecute = exporta_dbgrdExecute
    end
  end
end
